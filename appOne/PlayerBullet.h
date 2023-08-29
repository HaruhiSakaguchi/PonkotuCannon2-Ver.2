#pragma once
#include "SphereWeapon.h"

class PlayerBullet :
	public SphereWeapon
{
public:
	PlayerBullet(class Cannon* cannon, const VECTOR& pos, const VECTOR& dir);
	void UpdateActor()override;
	void damage()override;
	struct IDATA
	{
		//�T�E���h�{�̂Ƃ��ꂼ��̌��ʉ��̉��ʂ̒����l
		int mLaunchSound = -1;
		int mLaunchSoundVolumeOffset = 0;
		int mImpactSound = -1;
		int mImpactSoundVolumeOffset = 0;
		int mItemStockSound = -1;
		int mItemStockSoundVolumeOffset = 0;
	};
private:
	IDATA iData;
};

