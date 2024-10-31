#pragma once
public value struct SColor
{
public:
	float r;
	float g;
	float b;
	float a;

	SColor(float r, float g, float b, float a);
	SColor(int r, int g, int b, int a);
	SColor(float r, float g, float b);
	SColor(int r, int g, int b);

	//ПаµИ
	bool Equals(SColor other);

	static bool operator ==(SColor a, SColor b);
	static bool operator !=(SColor a, SColor b);

	virtual System::String^ ToString() override;

private:
	void Init(float r, float g, float b, float a);
};

