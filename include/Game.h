#include <string>
#include <array>
#include <SDL.h>
#include <SDL_image.h>

class Game
{
private:
    SDL_Window* m_window{nullptr};
    SDL_Renderer* m_renderer{nullptr};
    SDL_Event m_event;

    SDL_Rect m_rect;
    std::array<int, 2> m_rectPos = {250, 150};
    bool m_isRunning{false};
public:
    Game() = default;
    ~Game() = default;

    void initialize(std::string title, int x, int y, int w, int h, Uint32 flags);
    void handleEvents();
    void update();
    void render();
    void cleanUp();

    inline bool isRunning() { return m_isRunning; }
};