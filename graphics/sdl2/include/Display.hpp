#include "../../../include/IDisplay.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <map>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define GRID_PIXEL_SIZE (SCREEN_HEIGHT / 100)
#define GAME_BORDER_X ((SCREEN_WIDTH - SCREEN_HEIGHT) / 2)
#define REPEAT_DELAY 0
#define REPEAT_INTERVAL 200
class Display: public Arcade::IDisplay {
    public:
        Display();
        ~Display() override;

        void init() override;
        void stop() override;
        std::string getLibName() const override;
        void display(std::vector<std::unique_ptr<Arcade::IComponent>> &components) override;
        std::vector<std::unique_ptr<Arcade::IEvent>> &getEvents() override;
        void clear();

        static int calculateXPosition(int x);
        static int calculateYPosition(int y);
        static int calculateTextureSize(int sideSize);
        class DisplayException: public std::exception {
            public:
                DisplayException(std::string msg);
                ~DisplayException();
                const char *what() const noexcept override;
            private:
                const std::string _msg;
        };
    private:
        std::string _name;

        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_leftSideBar;
        SDL_Texture *_rightSideBar;

        std::map<int, std::string> _componentCache;
        std::map<std::string, SDL_Texture *> _textures;
        std::map<int, SDL_Texture *> _text;
        std::map<std::string, TTF_Font *> _fonts;
        std::vector<std::unique_ptr<Arcade::IEvent>> _events;
        // std::map<std::string, SDL_Sound *> _sounds;

        void _cacheLoadComponents(std::vector<std::unique_ptr<Arcade::IComponent>> &components);
        void _renderSides();

        void _updateTextComponents(std::vector<std::unique_ptr<Arcade::IComponent>> &components);
        void _renderCopy(std::vector<std::unique_ptr<Arcade::IComponent>> &components);
        void _renderCopyObject(std::unique_ptr<Arcade::IComponent> &object);
        void _renderCopyText(std::unique_ptr<Arcade::IComponent> &text);

        void _loadResource(std::unique_ptr<Arcade::IComponent> &component);
        void _loadObject(std::unique_ptr<Arcade::IComponent> &component);
        void _loadFont(std::unique_ptr<Arcade::IComponent> &component);
};
