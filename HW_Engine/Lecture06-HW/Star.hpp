#ifndef STAR_H
#define STAR_H

#include <GLFW/glfw3.h>

class Star {
private:
    float x, y; // 위치
    float r, g, b; // 색상

public:
    Star(); // 생성자 추가
    void render() const;
};

#endif // STAR_H
