#pragma once
#include <functional>
#include "COLOR.h"
#include "VECTOR2.h"
#include <string>
#include "sound.h"
#include "UIButton.h"

//���[�U�[�C���^�[�t�F�C�X���N���X
class UIScreen
{
public:
	UIScreen(class Game* game);
	virtual ~UIScreen();
	// �h���N���X�ŃI�[�o�[���C�h�\
	virtual void ProcessInput();
	virtual void Update() {};
	virtual void Draw();
	virtual void draw() {};
	virtual void DrawAfterButton() {};
	virtual void Closed() {};

	// UI�X�e�[�g�B�A�N�e�B�u���A���邩
	enum class UIState
	{
		EActive,
		EClosing
	};

	void SetBackPos(const VECTOR2& pos) { mBackPos = pos; }
	const VECTOR2& GetBackPos() { return mBackPos; }
	// UI�X�e�[�g��Closing�ɐݒ�
	void CloseMe();
	// UI�X�e�[�g���擾
	UIState GetState() const { return mState; }
	void SetState(UIState state) { mState = state; }
	// UI�^�C�g����ݒ�
	void SetTitle(const char* text) { mTitle = text; }
	const char* GetTitle() { return mTitle.c_str(); }

	std::vector<class Button*>& GetButtons() { return mButtons; }

	// �{�^����ǉ��i�c�ɔz�u����Ă����j
	class Button* AddRectButton(const char* name, std::function<void()> onClick, const char* text = 0, const VECTOR2 dim = VECTOR2(44.0f, 44.0f), const COLOR onColor = COLOR(200, 180, 116), const COLOR& offColor = COLOR(99, 163, 200));
	class Button* AddCircleButton(const char* name, std::function<void()> onClick, const char* text = 0, float radius = 50.0f, const COLOR onColor = COLOR(200, 180, 116), const COLOR& offColor = COLOR(99, 163, 200));

	void SetOtherUIButtonState(Button::ButtonState state);
	void SetOtherUIButtonBeforeState();
	void Line(const VECTOR2& p1, const VECTOR2& p2);
protected:
	class Game* mGame;
	// �X�e�[�g
	UIState mState;
	//�w�i�摜
	int mBackImg;
	VECTOR2 mBackPos;
	//�^�C�g�������Ƃ��̑���
	std::string mTitle;
	COLOR mTitleColor;
	VECTOR2 mTitlePos;
	float mTextSize;
	//�{�^��
	std::vector<class Button*> mButtons;
	VECTOR2 mButtonPos;
	COLOR mButtonTextcolor;
};

