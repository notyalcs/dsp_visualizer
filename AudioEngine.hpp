#pragma once

#include "fmod_studio.hpp"
#include "fmod.hpp"

#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <iostream>



struct Vector3 {
    float x;
    float y;
    float z;
};



struct Implementation {
    Implementation();
    ~Implementation();

    void Update();

    FMOD::Studio::System* mpStudioSystem;
    FMOD::System* mpSystem;

    int mNextChannelId;

    typedef std::map<std::string, FMOD::Sound*> SoundMap;
    typedef std::map<int, FMOD::Channel*> ChannelMap;
    typedef std::map<std::string, FMOD::Studio::EventInstance*> EventMap;
    typedef std::map<std::string, FMOD::Studio::Bank*> BankMap;

    BankMap mBanks;
    EventMap mEvents;
    SoundMap mSounds;
    ChannelMap mChannels;
};



class AudioEngine {
public:
    static void Init();
    static void Update();
    static void Shutdown();
    static int ErrorCheck(FMOD_RESULT result);

    void LoadBank(const std::string& bankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
    void LoadEvent(const std::string& eventName);
    void LoadSound(const std::string& soundName, bool b3d = true, bool bLooping = false, bool bStream = false);
    void UnLoadSound(const std::string& soundName);
    
    void Set3dListenerAndOrientation(const Vector3& pos = Vector3{ 0, 0, 0 }, float volumeDb = 0.0f);
    void SetChannel3dPosition(int channelId, const Vector3& pos);

    void PlaySound(const std::string& soundName, const Vector3& pos = Vector3{ 0, 0, 0}, float volumeDb = 0.0f);
    void PlayEvent(const std::string& eventName);
    void SetChannelVolume(int channelId, float volumeDb);
    
    void StopChannel(int channelId);
    void StopAllChannels();
    void StopEvent(const std::string& eventName, bool bImmediate = false);
    
    void GetEventParameter(const std::string& eventName, const std::string& eventParameter, float* parameter);
    void SetEventParameter(const std::string& eventName, const std::string& parameterName, float value);

    bool IsChannelPlaying(int channelId) const;
    bool IsEventPlaying(const std::string& eventName) const;

    float DbToVolume(float dB);
    float VolumeToDb(float volume);

    FMOD_VECTOR VectorToFmod(const Vector3& pos);
};
