namespace UI {
    class Style {
    public:
        static const int Bottom = 0;
        static const int Left = 0;
        static const int Center = 1;
        static const int Middle = 1;
        static const int Top = 2;
        static const int Right = 2;

        static const int Auto = -1;

        static const int None = 0;
        static const int Solid = 1;

        sf::Color color = sf::Color::Black;
        sf::Uint32 text_style = sf::Text::Regular; // sf::Text::Regular, sf::Text::Bold, sf::Text::Underlined, sf::Text::Italic
        std::string font = "None";
        int font_size = 12;

        sf::Color background_color = sf::Color::Transparent;

        int align_x = Left;
        int align_y = Top;

        int width = Auto;
        int height = Auto;

        int border_style = None;
        int border_width = 0;
        sf::Color border_color = sf::Color::Black;

        int padding_width = 0;

        Style() {}

        void Copy(Style& other);
    };

	bool LoadFont(std::string name, std::string file_path);
	bool DrawText(std::string text_to_write, int x, int y, Style& style);
    bool DrawPanel(int x, int y, Style& style);
    bool DrawButton(int x, int y, Style& style, Style& hover_style, Style& click_style);
}