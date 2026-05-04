#include <string>

class BaseObject {
protected:
	std::string name_;
	bool isAlive_;
public:
	BaseObject(const std::string name, const bool isAlive) {
		name_ = name;
		isAlive_ = isAlive;
	};
	~BaseObject() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
};