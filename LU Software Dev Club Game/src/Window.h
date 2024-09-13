namespace Window{
	void Setup(int window_width, int window_height, std::string window_name);
	void PollEvents();
	void Clear();
	void SetClearColor(int r, int g, int b);
	void Draw(sf::Drawable& drawable);
	void Render();

	bool IsOpen();

	sf::RenderWindow* GetWindow();
}