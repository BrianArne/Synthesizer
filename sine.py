import pyaudio
import numpy as np

p = pyaudio.PyAudio()

volume = 0.5     # amplitude
fs = 44100       # sampling rate
duration = 20.0   
f = 880        # frequency

duration_2 = 20.0
f_2 = 630.0

# array of float 32 (8ex, 23mantessa)
samples = (np.sin(2*np.pi*np.arange(duration*fs)*f/fs)).astype(np.float32)

# What happens when we add sine waves together? 
samples_2 = (np.sin(2*np.pi*np.arange(fs*duration)*f_2/fs)).astype(np.float32)

stream = p.open(format=pyaudio.paFloat32, channels=1, rate=fs, output=True)

stream.write(volume*samples)
#stream.write(volume*(samples + samples_2))


stream.stop_stream()
stream.close()

p.terminate()
