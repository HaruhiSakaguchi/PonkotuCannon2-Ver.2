#pragma once
#include "CharacterActor.h"
#include "MoveComponent.h"

class ActorsWeapon :
	public CharacterActor
{
public:
	ActorsWeapon(class CharacterActor* owner, const VECTOR& pos, const VECTOR& dir);
	virtual ~ActorsWeapon()override;
	virtual void damage();
	//mMoveFlagがfalseだとMoveComponentを使わない
	//getter,setter
	CharacterActor* GetOwner() { return mOwner; }
	void UnMoveComponent() { mMoveFlag = false; }
	const VECTOR& GetDir() { return mDir; }
	void SetDir(const VECTOR& dir) { mDir = dir; }
	//component
protected:
	class MoveComponent* mMove;
	//matrix
	MATRIX Master;
	CharacterActor* mOwner;
	VECTOR mTmpDir;
	VECTOR mTmpPos;
	//MoveComponentを使うかどうか
	bool mMoveFlag;
	VECTOR mDir;
};

