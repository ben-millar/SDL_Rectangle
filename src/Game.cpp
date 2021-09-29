#include "../include/Game.h"
#include <stdio.h>

void Game::initialize(std::string title, int x, int y, int w, int h, Uint32 flags)
{
    SDL_CreateWindowAndRenderer(w, h, flags, &m_window, &m_renderer);

    if (!(m_window && m_renderer)) {
        printf("Something went wrong while creating the SDL window and renderer: %s\n", SDL_GetError());
        exit(1);
    } else {
        m_isRunning = true;
    }
}

void Game::handleEvents()
{
    SDL_PollEvent(&m_event);

    switch(m_event.type)
    {
        case SDL_KEYDOWN:
            break;
        case SDL_KEYUP:
            break;
        case SDL_QUIT:
            m_isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_UP]) {
        m_rectPos[1]--;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        m_rectPos[1]++;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        m_rectPos[0]--;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        m_rectPos[0]++;
    }
}

void Game::render()
{
    SDL_RenderClear(m_renderer);

    m_rect.x = m_rectPos[0];
    m_rect.y = m_rectPos[1];
    m_rect.w = 200;
    m_rect.h = 200;

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(m_renderer, &m_rect);

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_renderer);
}

void Game::cleanUp()
{
    SDL_Quit();
}