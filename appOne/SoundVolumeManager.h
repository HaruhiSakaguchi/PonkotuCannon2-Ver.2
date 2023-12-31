#pragma once
#include "Manager.h"

class SoundVolumeManager
	:public Manager
{
public:
	SoundVolumeManager(class Game* game);
	~SoundVolumeManager();
	void LoadText(const char* fileName);
	void SaveText(const char* fileName);
public:
	int GetEffectVolume() { return mEffectVol; }
	int GetTmpEffectVolume() { return mTmpEffectVol; }
	void SetEffectVolume(int vol) { mEffectVol = vol; }
	void SetTmpEffectVolume(int vol) { mTmpEffectVol = vol; }
	int GetVolume() { return mSetVolume; }
	int GetTmpVolume() { return mTmpVolume; }
	void SetVolume(int vol) { mSetVolume = vol; }
	void SetTmpVolume(int vol) { mTmpVolume = vol; }
	bool GetSoundFlag() { return mSoundFlag; }
	void SetSoundFlag(bool flag) { mSoundFlag = flag; }
	bool GetBgmFlag() { return mBgmFlag; }
	void SetBgmFlag(bool flag) { mBgmFlag = flag; }
	void EffectPlay(int sound = -1,int volumeoffset = 0);
	void BGMPlay(int sound = -1, int volumeoffset = 0,bool loop = true);

private:
	int mTmpVolume;//音声OFF時にON時のボリュームをとっておく
	int mSetVolume;
	int mEffectVol;
	int mTmpEffectVol;
	bool mSoundFlag;
	bool mBgmFlag;
	const char* mSaveFileName = "Assets\\option\\Sound.txt";
};

