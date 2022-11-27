#pragma once

#include <string>
#include <map>
#include <list>
#include <vector>
#include <functional>

using ArgsVector = std::vector<std::pair<std::string, int>>;

class Wrapper {
private:
	class Command {
	public:
		Command() = default;

		template<typename Class, typename ...Args>
		Command(Class* cls, int(Class::* newCommand)(Args...)) {
			_funcCaller = [cls, newCommand](const std::vector<int>& funcArgs) {
				return callFunc(cls, newCommand, funcArgs, std::make_index_sequence<sizeof...(Args)>{});
			};
		}

		int executeCommand(const std::vector<int>& funcArgs) {
			return _funcCaller(funcArgs);
		}
	private:
		std::function<int(const std::vector<int>& args)> _funcCaller;

		template<typename Class, typename Func, int ...indexies>
		static int callFunc(Class* cls, Func function, const std::vector<int>& args, std::index_sequence<indexies...>) {
			return (cls->*function)(args[indexies]...);
		}
	};

	Command _command;
	std::vector<std::string> _argsName;
	std::vector<int> _values;

	bool isSimilarArgsName(const ArgsVector& args) {
		for (int i = 0; i < args.size(); i++)
			for (int j = i + 1; j < args.size(); j++)
				if (args[i].first == args[j].first)
					return true;
		return false;
	}

	void checkCorrectArgs(ArgsVector& args) {
		bool correct = true;
		for (int i = 0; i < args.size(); i++) {
			correct = false;
			for (int j = 0; j < _argsName.size(); j++)
				if (args[i].first == _argsName[j]) {
					correct = true;
					_values[j] = args[i].second;
					break;
				}
			if (!correct) {
				throw std::exception("Wrapper correctness check exception: unknown argument name");
			}
		}
	}
public:
	Wrapper() = delete;

	template<typename Class, typename ...Args>
	Wrapper(Class* cls, int(Class::* newCommand)(Args...), const ArgsVector& args) {
		if (cls == nullptr || newCommand == nullptr)
			throw std::exception("Wrapper init exception: unexpected nullptr");
		if (isSimilarArgsName(args))
			throw std::exception("Wrapper init exception: arguments have same names");
		if (args.size() != sizeof...(Args))
			throw std::exception("Wrapper init exception: incorrect count of arguments");
		_command = Command(cls, newCommand);
		_argsName = std::vector<std::string>(args.size());
		_values = std::vector<int>(args.size());
		int i = 0;
		for (auto& arg : args) {
			_argsName[i] = arg.first;
			_values[i] = arg.second;
			i++;
		}
	}

	int execute(ArgsVector args = {}) {
		checkCorrectArgs(args);
		return _command.executeCommand(_values);
	}
};