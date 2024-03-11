#include "cppss.hpp"
#include "../lib/raylib/cpp/raylib-cpp.hpp"

Logger logger;

void drawingFunctionWrapper(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {

    DrawPixel(xpos, ypos, raylib::Color(r, g, b, a));
}

int main() {

    RWindow window(800, 600, "CPPSS Example");

    window.SetTargetFPS(60);

    CPPSS::Html page;

    page.size(800, 600);
    page.setDrawingFunction(drawingFunctionWrapper);
    page.addCssFile("style.css");
    page.body(page.div("id2", "class2", {

        page.div("id3", "class3"

        ),

        page.div("id4", "class4", {

            page.div("id6", "class6"),

        }),

        page.div("id5", "class5"

        )

    }));

    // while (!window.ShouldClose()) {

    //     window.BeginDrawing();
    //     window.ClearBackground(BLACK);
        page.draw();
    //     window.EndDrawing();
    // }

    window.Close();

    return 0;
}
