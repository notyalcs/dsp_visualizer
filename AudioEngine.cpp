#include "AudioEngine.hpp"



Implementation::Implementation()
{
}

Implementation::~Implementation()
{
}

void Implementation::Update()
{
}

void AudioEngine::Init()
{
}

void AudioEngine::Update()
{
}

void AudioEngine::Shutdown()
{
}

int AudioEngine::ErrorCheck(FMOD_RESULT result)
{
    return 0;
}

void AudioEngine::LoadBank(const std::string &bankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags)
{
}

void AudioEngine::LoadEvent(const std::string &eventName)
{
}

void AudioEngine::LoadSound(const std::string &soundName, bool b3d, bool bLooping, bool bStream)
{
}

void AudioEngine::UnLoadSound(const std::string &soundName)
{
}

void AudioEngine::Set3dListenerAndOrientation(const Vector3 &pos, float volumeDb)
{
}

void AudioEngine::SetChannel3dPosition(int channelId, const Vector3 &pos)
{
}

void AudioEngine::PlaySound(const std::string &soundName, const Vector3 &pos, float volumeDb)
{
}

void AudioEngine::PlayEvent(const std::string &eventName)
{
}

void AudioEngine::SetChannelVolume(int channelId, float volumeDb)
{
}

void AudioEngine::StopChannel(int channelId)
{
}

void AudioEngine::StopAllChannels()
{
}

void AudioEngine::StopEvent(const std::string &eventName, bool bImmediate)
{
}

void AudioEngine::GetEventParameter(const std::string &eventName, const std::string &eventParameter, float *parameter)
{
}

void AudioEngine::SetEventParameter(const std::string &eventName, const std::string &parameterName, float value)
{
}

bool AudioEngine::IsChannelPlaying(int channelId) const
{
    return false;
}

bool AudioEngine::IsEventPlaying(const std::string &eventName) const
{
    return false;
}

float AudioEngine::DbToVolume(float dB)
{
    return 0.0f;
}

float AudioEngine::VolumeToDb(float volume)
{
    return 0.0f;
}

FMOD_VECTOR AudioEngine::VectorToFmod(const Vector3 &pos)
{
    return FMOD_VECTOR();
}
