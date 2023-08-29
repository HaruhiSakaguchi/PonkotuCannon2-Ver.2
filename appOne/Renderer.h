#pragma once
#include <vector>
#include "VECTOR.h"
#include "COLOR.h"
#include "MATRIX.h"

class Renderer
{
public:
	Renderer(class Game* game);
	~Renderer();

	bool Initialize();
	void Shutdown();
	void Draw();

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	void AddMesh(class MeshComponent* mesh);
	void RemoveMesh(class MeshComponent* mesh);
	class SHADER* GetShader() { return mShader; }
	class CONTAINER* GetContainer() { return mContainer; }
	void SetView(class MATRIX& view) { mView = view; }

	bool LoadContainer();
	const MATRIX GetProj() { return mProj; }
	const MATRIX GetView() { return mView; }

	class TransitionFade* GetTransition() { return mTransition; }

	struct DATA
	{
		float mAmbient = 0.0f;
		COLOR mDiffuse;
		VECTOR mCamPos;
		VECTOR mLookat;
		VECTOR mUp;
		VECTOR mLightPos;
		float mPerspectiveAngle = 0.0f;
		float mPerspectiveAspect = 0.0f;
		float mPerspectiveNear = 0.0f;//�߂��̃N���b�s���O����zNear
		float mPerspectiveFar = 0.0f;//�����̃N���b�s���O����zFar
	};
private:
	DATA Data;
private:
	class SHADER* mShader;
	class CONTAINER* mContainer;
	class TransitionFade* mTransition;
	std::vector<class MeshComponent*>mMeshes;

	MATRIX mView;
	MATRIX mProj;
	class Game* mGame;
	std::vector<class SpriteComponent*>mSprites;
};
