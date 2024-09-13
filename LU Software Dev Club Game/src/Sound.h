namespace Sound {
	bool LoadSound(std::string name, std::string file_path);
	bool PlaySound(std::string name, bool wait_if_playing=false);
}