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
	//mMoveFlag��false����MoveComponent���g��Ȃ�
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
	//MoveComponent���g�����ǂ���
	bool mMoveFlag;
	VECTOR mDir;
};

