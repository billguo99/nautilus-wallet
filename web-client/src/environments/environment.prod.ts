import { Environment } from 'src/environments/types';

export const environment: Environment = {
  production: true,

  // Enable persistence for demo purposes.
  persistAkitaState: true,
  // TODO: Production endpoint
  nautilusWalletServer: 'https://ntls-api.registree.io/',
  nautilusAssetServices: 'https://ntls-services.registree.io/',
  algod: {
    baseServer: 'https://testnet-algorand.api.purestake.io/ps2',
    port: '',
    // FIXME: Development key
    token: { 'X-API-Key': 'J7eo2jPb5m4OiBneIV6r0ajgRLeSaHqk3QplGETk' },
  },
  // USDC from https://testnet.folks.finance/faucet
  defaultAlgorandAssetId: 67395862,
  xrplClient: {
    server: 'wss://s.altnet.rippletest.net/',
    options: {
      connectionTimeout: 20000,
    },
  },
};
