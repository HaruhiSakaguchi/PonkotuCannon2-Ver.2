#include "UICircleButton.h"
#include "input.h"

CircleButton::CircleButton(const char* name, std::function<void()> onClick, const VECTOR2& pos, float radius, Game* game, const char* text, const VECTOR2& textOffset)
	:Button(name, onClick, pos, game, text, textOffset)
	, mRadius(radius)
{
}

bool CircleButton::ContainsPoint(const VECTOR2& pt, bool flag)
{
	bool no = true;

	VECTOR2 vec = mPosition - pt;

	float dist = sqrt(vec.x * vec.x + vec.y * vec.y);

	no = dist > mRadius;

	if (mState != ButtonState::EEnable)
	{
		no = true;
	}

	mHighlighted = !no;

	//�{�^���̊O�Ƀ}�E�X�J�[�\�����������玟�Ƀ{�^���ɐG�ꂽ�Ƃ��ɉ������Đ�����悤�ɂ���
	if (no)
	{
		mSoundFlag = false;
	}

	return !no;
}

void CircleButton::Draw()
{
	if (mState != Button::ButtonState::EDisable)
	{
		VECTOR2 mousePos = VECTOR2(mouseX, mouseY);

		if (ContainsPoint(mousePos) && GetText())
		{
			DrawGuide();
		}

		COLOR color = mHighlighted ? mContainsColor : mNoContainsColor;
		stroke(Data.mButtonTextColor);
		strokeWeight(Data.mButtonSw);
		fill(color);
		circle(mPosition.x, mPosition.y, mRadius * 2.0f);

		// �{�^�������\��
		textSize(Data.mButtonTextSize);
		VECTOR2 pos;
		pos.x = mPosition.x - mName.length() * Data.mButtonTextSize / 4.0f + mNameOffset.x;//���p�����̂ݑΉ�
		pos.y = mPosition.y + Data.mButtonTextSize / 2.0f - Data.mTopShadowSw + mNameOffset.y;
		fill(Data.mButtonTextColor);
		text(mName.c_str(), pos.x, pos.y);
	}

	if (mState == Button::ButtonState::EDraw_Enable)
	{
		stroke(Data.mDraw_EnableButtonColor);
		fill(Data.mDraw_EnableButtonColor);
		circle(mPosition.x, mPosition.y, mRadius * 2.0f);
	}

}
