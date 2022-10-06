#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <map>

// static�Լ��� �̿��ؼ� Ű���� �� ���콺 �Է��� �˻��� �� �ִ� Ŭ����

using namespace sf;
using namespace std;

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;
	list<Keyboard::Key> positives;
	list<Keyboard::Key> negatives;
};

class InputMgr
{
private:
	static map<Axis, AxisInfo> axisInfoMap;

	static vector<bool> downList;
	static vector<bool> ingList;
	static vector<bool> upList;
	static list<Keyboard::Key> keyList;
public:
	static void Init();
	static void ClearInput();
	static void UpdateInput(const Event& ev);

	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);

	static float GetAxisRaw(Axis axis);
};
