//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_CONSTANT_H
#define PONG_NETWORK_CONSTANT_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_FG 0xffffffff
#define SCREEN_BALL 0xffffffff
#define SCREEN_BG 0x000000ff
#define WIN_SCORE 3
#define LOOP_TIME 20	// 50 frames par seconde

#define BALL_WIDTH 10
#define BALL_HEIGHT 10
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 100
#define PADDLE_STEP 10

#define SERVER_HOST "127.0.0.1"//"192.168.2.40"
#define SERVER_PORT 63476
#define DATA_BUFFER_CLIENT 127
#define DATA_BUFFER_SERVER 255
// In seconds :
#define SERVER_CLIENT_TIMEOUT 3

#endif //PONG_NETWORK_CONSTANT_H
