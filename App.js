/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import {SafeAreaView, StyleSheet, Button, View} from 'react-native';

const App: () => Node = () => {
  const sendBackwardRequest = () => {
    fetch('http://192.168.4.1/backward');
  };

  const sendForwardRequest = () => {
    fetch('http://192.168.4.1/forward');
  };

  const sendLeftRequest = () => {
    fetch('http://192.168.4.1/left');
  };

  const sendRightRequest = () => {
    fetch('http://192.168.4.1/right');
  };

  return (
    <SafeAreaView style={styles.pageCenter}>
      <Button
        title="Go Backward"
        style={styles.directionButton}
        onPress={sendBackwardRequest}
      />
      <View style={styles.leftRightCenterer}>
        <Button
          title="Go Left"
          style={styles.directionButton}
          onPress={sendLeftRequest}
        />
        <Button
          title="Go Right"
          style={styles.directionButton}
          onPress={sendRightRequest}
        />
      </View>
      <Button
        title="Go Forward"
        style={styles.directionButton}
        onPress={sendForwardRequest}
      />
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

  leftRightCenterer: {
    width: '60%',
    flexDirection: 'row',
    justifyContent: 'space-between',
  },

  directionButton: {
    borderRadius: 100,
    backgroundColor: 'orange',
    justifyContent: 'center',
    alignItems: 'center',
  },
});

export default App;
