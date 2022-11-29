#pragma once

#include <map>
#include <vector>
#include <string>

#include "../wrapper/wrapper.h"

using ArgsVector = std::vector<std::pair<std::string, int>>;

class Engine {
private:
	std::map<std::string, Wrapper*> _commands;
public:
	void register_command(Wrapper* command, const std::string& commandName) {
		if (command == nullptr)
			throw std::exception("Engine register command exception: unexpected nullptr from command");
		if (_commands.find(commandName) != _commands.end())
			throw std::exception("Engine register command exception: this command is already registered");
		_commands[commandName] = command;
	}

	int execute(const std::string& commandName, ArgsVector args = {}) {
		if (_commands.find(commandName) == _commands.end())
			throw std::exception("Engine execute exception: unknown command");
		return _commands[commandName]->execute(args);
	}
};