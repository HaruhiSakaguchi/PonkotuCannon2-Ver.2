#include "StageClear.h"
#include "Quit.h"
#include "Title.h"
#include "GamePlay.h"
#include "AllClear.h"
#include "Game.h"
#include "TransitionFade.h"

StageClear::StageClear(Game* game)
	: UIMainState(game)
	, mIsChangeTitle(false)
	, mIsChangeAllClear(false)
{
	Data = mGame->GetAllData()->stageClearData;

	mTitle = Data.mTitle;
	mTitleColor = Data.mTitleColor;
	mTextSize = Data.mTextSize;;
	mTitlePos = Data.mTitlePos;
	mButtonPos = Data.mButtonPos;
	mMState = State::EStageClear;

	mGame->GetRenderer()->GetTransition()->inTrigger();
	mGame->SetPhase(static_cast<Game::StagePhase>((int)mGame->GetPhase() + 1));

	mClearTimeText = mGame->GetActorManager()->GetStage()->GetTimeText();

	AddRectButton(Data.mNextText,
		[this]() {
			mIsChangeAllClear = true;
			ChangeState();
		}
		, Data.mNextButtonGuide
			, mGame->GetAllData()->buttonData.mBasicButtonDim
			);

	AddRectButton(Data.mReturnTitleText,
		[this]() {
			mIsChangeTitle = true;
			ChangeState();
		}
		, Data.mReturnTitleButtonGuide
			, mGame->GetAllData()->buttonData.mBasicButtonDim
			);

	AddRectButton(Data.mQuitText,
		[this]() {
			new Quit(mGame);
		}
		, Data.mQuitButtonGuide
			, mGame->GetAllData()->buttonData.mBasicButtonDim
			);


	if (mGame->GetPhase() != Game::StagePhase::EFOURTH)
	{
		mGame->GetSoundVolumeManager()->BGMPlay(Data.mSound,0,false);
	}
	else
	{
		mGame->GetSoundVolumeManager()->BGMPlay(Data.mSound2, 0, false);
	}



	SetOtherUIButtonState(Button::ButtonState::EDisable);
}

void StageClear::ChangeOption()
{
	mGame->GetActorManager()->ActorClear();

	if (mIsChangeTitle)
	{
		new Title(mGame);
		mGame->GetRenderer()->GetTransition()->inTrigger();
	}
	else if (mIsChangeAllClear)
	{
		new AllClear(mGame);
	}
}

void StageClear::Draw()
{
	UIScreen::Draw();
	textSize(Data.mClearTimeTextSize);
	text((let)"クリアタイム : " + (let)mClearTimeText.c_str(), width / 2.0f - Data.mClearTimeTextSize * (9 + mClearTimeText.length()) / 4.0f, Data.mTitlePos.y + Data.mClearTimeTextSize * 10.0f);
}

void StageClear::Closed()
{
	if (mGame->GetPhase() == Game::StagePhase::EFOURTH)
	{
		stopSound(Data.mSound2);
	}
	else
	{
		stopSound(Data.mSound);
	}

}
