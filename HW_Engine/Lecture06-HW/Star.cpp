#include "Star.hpp"
#include <cstdlib> // for rand()

Star::Star() {
    // 랜덤한 위치 설정 (-1.0 ~ 1.0)
    x = static_cast<float>(rand()) / RAND_MAX * 2.0 - 1.0;
    y = static_cast<float>(rand()) / RAND_MAX * 2.0 - 1.0;

    // 랜덤한 색상 설정 (0.0 ~ 1.0)
    r = static_cast<float>(rand()) / RAND_MAX;
    g = static_cast<float>(rand()) / RAND_MAX;
    b = static_cast<float>(rand()) / RAND_MAX;
}

void Star::render() const {
    float scale_factor = 0.1f;

    glBegin(GL_TRIANGLES);

    glColor3f(r, g, b);
    glVertex2f(x + 0.0f * scale_factor, y + 0.25f * scale_factor);
    glVertex2f(x - 0.15f * scale_factor, y - 0.25f * scale_factor);
    glVertex2f(x + 0.1f * scale_factor, y - 0.05f * scale_factor);

    glVertex2f(x + 0.0f * scale_factor, y + 0.25f * scale_factor);
    glVertex2f(x + 0.15f * scale_factor, y - 0.25f * scale_factor);
    glVertex2f(x - 0.1f * scale_factor, y - 0.05f * scale_factor);

    glVertex2f(x - 0.25f * scale_factor, y + 0.05f * scale_factor);
    glVertex2f(x + 0.25f * scale_factor, y + 0.05f * scale_factor);
    glVertex2f(x + 0.0f * scale_factor, y - 0.13f * scale_factor);

    glEnd();
}
