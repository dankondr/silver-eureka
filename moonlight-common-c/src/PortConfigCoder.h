#ifndef PORT_CONFIG_LIBRARY_H
#define PORT_CONFIG_LIBRARY_H

enum {
  CONFIG_HTTP_PORT = 0,
  CONFIG_HTTPS_PORT = 1,
  CONFIG_RTSP_SETUP_PORT = 2,
  CONFIG_VIDEO_STREAM_PORT = 3,
  CONFIG_CONTROL_PORT = 4,
  CONFIG_AUDIO_STREAM_PORT = 5,
  CONFIG_FIRST_FRAME_PORT = 6,
  CONFIG_PORTS_NUMBER = 7
};

char *config_file_path = "config.txt";

// pcc = port config coder
int *pcc_getPortsFromConfig();

#endif//PORT_CONFIG_LIBRARY_H
