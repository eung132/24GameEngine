#ifndef STAR_H
#define STAR_H

#include <GLFW/glfw3.h>

class Star {
private:
    float x, y; // ��ġ
    float r, g, b; // ����

public:
    Star(); // ������ �߰�
    void render() const;
};

#endif // STAR_H
