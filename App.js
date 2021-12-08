/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import {SafeAreaView, StyleSheet, Button} from 'react-native';

const App: () => Node = () => {
  const sendBackwardRequest = () => {
    fetch('http://192.168.4.1/backward');
  };

  const sendForwardRequest = () => {
    fetch('http://192.168.4.1/forward');
  };

  return (
    <SafeAreaView style={styles.pageCenter}>
      <Button title="Go Backward" style={styles.directionButton} onPress={sendBackwardRequest} />
      <Button title="Go Forward" style={styles.directionButton} onPress={sendForwardRequest} />
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  pageCenter: {
    width: '100%',
    height: '100%',
    justifyContent: 'center',
    alignItems: 'center',
  },

  directionButton: {
    width: 160,
    height: 160,
    borderRadius: 100,
    backgroundColor: 'orange',
    marginBottom: 30,
    justifyContent: 'center',
    alignItems: 'center',
  },
});

export default App;
