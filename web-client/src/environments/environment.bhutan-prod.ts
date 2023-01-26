import { Environment } from 'src/environments/types';

export const environment: Environment = {
  firebase: {
    projectId: 'wallet-setup',
    appId: '1:907972056790:web:18c0095eccf21eedf15b77',
    databaseURL:
      'https://wallet-setup-default-rtdb.europe-west1.firebasedatabase.app',
    storageBucket: 'wallet-setup.appspot.com',
    apiKey: 'AIzaSyDPq5JcM2dVVYisvvqANjJipKInkMdy_zc',
    authDomain: 'wallet-setup.firebaseapp.com',
    messagingSenderId: '907972056790',
    measurementId: 'G-TW4DGPTJ62',
  },
  production: true,
  organization: 'bhutan',

  // Enable persistence for demo purposes.
  persistAkitaState: true,
  nautilusWalletServer: 'https://wallet-bhutan-api.ntls.io/',
  nautilusAssetServices: 'https://wallet-bhutan-services.ntls.io/',
  xrplClient: {
    server: 'wss://uuvvvai.com:51233',
    options: {
      connectionTimeout: 20000,
    },
  },
  commissionPercentage: 0.0,
  tokenIssuer: 'rDzwrgetpdAwSU226dTbk6BQye1tJthCMa',
  tokenSymbol: 'BTN',
  xrpIssuer: 'rfgasaRgZYJMxPEuAWUPH2ShSBhQJQFHCh',
  hideXrpBalance: true,
  autofundXrp: true,
  hidePullPayment: true,
  enableQuickAccess: false,
  autoLogout: false,
  autofundXrpAmount: 50,
  autofundAccountPin: 'uzD3Y8idq6*x8vGwWxRC',
  autofundXrpPublicKey:
    '0208A1EE854F42E720F700CE4687D75838A92EA7F630F2964F1457D61623CA6E1D',
};
