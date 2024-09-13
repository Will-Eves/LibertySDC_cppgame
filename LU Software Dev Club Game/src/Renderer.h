namespace Renderer {
	bool LoadSprite(std::string name, std::string file_path, bool smooth=false);
	bool DrawSprite(std::string texture, int x, int y, int width, int height, bool flipped=false);
}