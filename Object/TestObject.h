#include "BaseObject.h"

class TestObject : public BaseObject {
private:
public:
	TestObject();
	~TestObject();
	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};