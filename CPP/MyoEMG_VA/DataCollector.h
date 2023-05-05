class DataCollector : public myo::DeviceListener {
public:
	uint8_t bat_level;
	DataCollector()
		: emgSamples()
	{
	}
	void onUnpair(myo::Myo* myo, uint64_t timestamp)
	{
		emgSamples.fill(0);
	}

	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
	{
		for (int i = 0; i < 8; i++) {
			emgSamples[i] = emg[i];
		}
	}

	void onBatteryLevelReceived(myo::Myo *myo, uint64_t timestamp, uint8_t level)
	{
		bat_level = level;
	}

	void vibrate(myo::Myo::VibrationType type)
	{

	}
	std::array<int8_t, 8> emgSamples;
};