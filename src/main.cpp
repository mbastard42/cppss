#include "../inc/cppss.hpp"
#include "../lib/raylib/cpp/raylib-cpp.hpp"

Logger logger;

void drawingFunctionWrapper(int xpos, int ypos, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {

    DrawPixel(xpos, ypos, {r, g, b, a});
}

int main() {

    // RWindow window(800, 600, "CPPSS Example");
    // window.SetTargetFPS(60);

    cppss::CssFile styleSheet;
    styleSheet.open("style.css");

    cppss::HtmlPage page(800, 600, drawingFunctionWrapper);

    // page.addCssFile(styleSheet);
    // page.body(page.div("id2", "class2", {

    //     page.div("id3", "class3"

    //     ),

    //     page.div("id4", "class4", {

    //         page.div("id6", "class6"),

    //     }),

    //     page.div("id5", "class5"

    //     )

    // }));

    std::cout << styleSheet;

    // std::cout << page;

    // while (!window.ShouldClose()) {

    //     window.BeginDrawing();
    //     window.ClearBackground(BLACK);
    //     page.draw();
    //     window.EndDrawing();
    // }

    // window.Close();

    return 0;
}
