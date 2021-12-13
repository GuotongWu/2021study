[y,Fs] = audioread("audio.wav");
time = (0:length(y)-1) / Fs;
sound(y(:,1), Fs)