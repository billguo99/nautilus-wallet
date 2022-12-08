from unittest.mock import AsyncMock

import pytest
from motor import motor_asyncio
from pymongo.results import DeleteResult, InsertOneResult
from pytest_mock import MockerFixture

from common.types import WalletAddress
from data_service.operations.bookmark import bookmarks, create_bookmark, delete_bookmark
from data_service.schema.actions import (
    CreateBookmark,
    CreateBookmarkResult,
    DeleteBookmark,
    DeleteBookmarkResult,
    GetBookmarks,
    GetBookmarksResult,
)
from data_service.schema.entities import Bookmark
from tests.data_service.operations.helpers import mock_settings


@pytest.mark.asyncio
async def test_create_bookmark_success(mocker: MockerFixture) -> None:
    mock_insert_one = AsyncMock(return_value=InsertOneResult(None, acknowledged=True))
    mocker.patch("data_service.operations.bookmark.mongo_settings", mock_settings)
    mocker.patch.object(
        motor_asyncio.AsyncIOMotorCollection, "insert_one", new=mock_insert_one
    )
    client = motor_asyncio.AsyncIOMotorClient("mongodb://localhost:27017")
    mocker.patch("motor.motor_asyncio.AsyncIOMotorClient")

    params = CreateBookmark(
        wallet_id=WalletAddress("test_id"),
        bookmark=Bookmark(name="test_name", address=WalletAddress("test_address")),
    )

    assert await create_bookmark(client, params) == CreateBookmarkResult(success=True)
    mock_insert_one.assert_awaited_once_with(params)


@pytest.mark.asyncio
async def test_delete_bookmark_success(mocker: MockerFixture) -> None:
    mock_delete_one = AsyncMock(return_value=DeleteResult({}, acknowledged=True))
    mocker.patch("data_service.operations.bookmark.mongo_settings", mock_settings)
    mocker.patch.object(
        motor_asyncio.AsyncIOMotorCollection,
        "delete_one",
        new=mock_delete_one,
    )
    client = motor_asyncio.AsyncIOMotorClient("mongodb://localhost:27017")
    mocker.patch("motor.motor_asyncio.AsyncIOMotorClient")

    params = DeleteBookmark(
        wallet_id=WalletAddress("test_id"),
        bookmark=Bookmark(name="test_name", address=WalletAddress("test_address")),
    )

    assert await delete_bookmark(client, params) == DeleteBookmarkResult(success=True)
    mock_delete_one.assert_awaited_once_with(filter=params)


@pytest.mark.asyncio
async def test_get_bookmarks_success(mocker: MockerFixture) -> None:
    stored_docs = [
        {
            "wallet_id": "test_id1",
            "bookmark": {"name": "test_name1", "address": "test_address1"},
        },
        {
            "wallet_id": "test_id2",
            "bookmark": {"name": "test_name2", "address": "test_address2"},
        },
    ]
    mock_to_list = AsyncMock(return_value=stored_docs)
    mocker.patch("data_service.operations.bookmark.mongo_settings", mock_settings)
    mocker.patch.object(
        motor_asyncio.AsyncIOMotorCursor,
        "to_list",
        new=mock_to_list,
    )
    client = motor_asyncio.AsyncIOMotorClient("mongodb://localhost:27017")
    mocker.patch("motor.motor_asyncio.AsyncIOMotorClient")

    params = GetBookmarks(wallet_id=WalletAddress("test_id"))
    expected_bookmarks = [Bookmark.parse_obj(doc["bookmark"]) for doc in stored_docs]
    assert await bookmarks(client, params) == GetBookmarksResult(
        bookmarks=expected_bookmarks
    )
    mock_to_list.assert_awaited_once_with(mock_settings.max_list_length)
