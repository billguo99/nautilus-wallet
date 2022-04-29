/**
 * Types and code for working with XRP on the XRP ledger.
 *
 * 1. {@link AssetDisplay} constant: {@link ASSET_DISPLAY_XRP}
 * 2. {@link LedgerInfo} constant: {@link LEDGER_INFO_XRPL}
 * 3. {@link AssetAmount} constructor: {@link assetAmountXrp}
 */
import { defined } from 'src/app/utils/errors/panic';
import { parseNumber } from 'src/app/utils/validators';
import * as xrpl from 'xrpl';
import { AssetAmount, AssetDisplay, LedgerInfo } from './assets.common';

// AssetDisplay:

export type AssetSymbolXrp = 'XRP';

export const ASSET_SYMBOL_XRP: AssetSymbolXrp = 'XRP';

export type AssetDisplayXrp = AssetDisplay & {
  assetSymbol: AssetSymbolXrp;
  maxDigits: 6;
};

export const ASSET_DISPLAY_XRP: AssetDisplayXrp = {
  assetSymbol: ASSET_SYMBOL_XRP,
  minDigits: 0,
  maxDigits: 6,
};

// LedgerInfo:

export type LedgerTypeXrpl = 'XRPL';

export const LEDGER_TYPE_XRPL: LedgerTypeXrpl = 'XRPL';

export type LedgerInfoXrpl = LedgerInfo & {
  type: LedgerTypeXrpl;
};

export const LEDGER_INFO_XRPL: LedgerInfoXrpl = {
  type: LEDGER_TYPE_XRPL,
};

// AssetAmount:

export type AssetAmountXrp = AssetAmount & {
  assetDisplay: AssetDisplayXrp;
  ledgerInfo: LedgerInfoXrpl;
};

export const assetAmountXrp = (amount: number): AssetAmountXrp => ({
  amount,
  assetDisplay: ASSET_DISPLAY_XRP,
  ledgerInfo: LEDGER_INFO_XRPL,
});

// Type checks:

export const isAssetAmountXrp = (
  amount: AssetAmount | AssetAmountXrp
): amount is AssetAmountXrp =>
  amount.ledgerInfo.type === LEDGER_TYPE_XRPL &&
  amount.assetDisplay.assetSymbol === ASSET_SYMBOL_XRP;

// Ledger representation conversion:

export const convertFromLedgerToAssetAmountXrp = (
  ledgerAmount: string
): AssetAmountXrp =>
  assetAmountXrp(
    defined(
      parseNumber(xrpl.dropsToXrp(ledgerAmount)),
      `bad number: ${ledgerAmount}`
    )
  );

export const convertFromAssetAmountXrpToLedger = (
  assetAmount: AssetAmountXrp
): string => xrpl.xrpToDrops(assetAmount.amount);
