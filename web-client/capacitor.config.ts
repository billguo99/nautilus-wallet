import { CapacitorConfig } from '@capacitor/cli';

const config: CapacitorConfig = {
  appId: 'io.ionic.starter',
  appName: 'Nautilus wallet',
  webDir: 'www',
  bundledWebRuntime: false,
  plugins: {
    Keyboard: {
      resize: 'none',
    },
  },
};

export default config;
