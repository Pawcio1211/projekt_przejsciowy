close all
instrreset
clear
clc
data = 0;
EMG_1 = 0;
EMG_2 = 0;
EMG_3 = 0;
EMG_4 = 0;
EMG_5 = 0;
EMG_6 = 0;
EMG_7 = 0;
EMG_8 = 0;

TAB_EMG_1 = zeros(50,1);
TAB_EMG_2 = zeros(50,1);
TAB_EMG_3 = zeros(50,1);
TAB_EMG_4 = zeros(50,1);
TAB_EMG_5 = zeros(50,1);
TAB_EMG_6 = zeros(50,1);
TAB_EMG_7 = zeros(50,1);
TAB_EMG_8 = zeros(50,1);

a_11 = 1;
angle_1 = 30;
angle_2 = 20;
angle_3 = 20;
angle_4 = 20;
angle_5 = 20;

allow = 1;
    PORT = 7766;
    %UDPsock = udpport ('DatagramTerminateMode', 'IPV4',  '127.0.0.1','LocalPort', PORT)
    UDPsock=udp('127.0.0.1', 'LocalPort', 7766, 'Timeout', 2)
    set(UDPsock, 'DatagramTerminateMode','off');
    figure;
    fopen(UDPsock);
    while 1
                data = fread(UDPsock, 32, 'char');
                data_char = char(data);
                if (isempty(data_char) == 0)
                    if(data_char(1)~='a')
                        while(data_char(1)~='a')
                            data_char = shift_register_loop(32,data_char);
                        end
                    else
                        EMG_1 = (str2double(data_char(2))*100)+...
                            (str2double(data_char(3))*10)+...
                            (str2double(data_char(4))*1)-500;
                        EMG_2 = (str2double(data_char(6))*100)+...
                            (str2double(data_char(7))*10)+...
                            (str2double(data_char(8))*1)-500;
                        EMG_3 = (str2double(data_char(10))*100)+...
                            (str2double(data_char(11))*10)+...
                        (str2double(data_char(12))*1)-500;
                        EMG_4 = (str2double(data_char(14))*100)+...
                            (str2double(data_char(15))*10)+...
                        (str2double(data_char(16))*1)-500;
                        EMG_5 = (str2double(data_char(18))*100)+...
                            (str2double(data_char(19))*10)+...
                        (str2double(data_char(20))*1)-500;
                        EMG_6 = (str2double(data_char(22))*100)+...
                            (str2double(data_char(23))*10)+...
                        (str2double(data_char(24))*1)-500;
                        EMG_7 = (str2double(data_char(26))*100)+...
                            (str2double(data_char(27))*10)+...
                        (str2double(data_char(28))*1)-500;
                        EMG_8 = (str2double(data_char(30))*100)+...
                        (str2double(data_char(31))*10)+...
                        (str2double(data_char(32))*1)-500;

                        TAB_EMG_1 = shift_register(size(TAB_EMG_1,1), TAB_EMG_1, EMG_1);
                        TAB_EMG_2 = shift_register(size(TAB_EMG_1,1), TAB_EMG_2, EMG_2);
                        TAB_EMG_3 = shift_register(size(TAB_EMG_1,1), TAB_EMG_3, EMG_3);
                        TAB_EMG_4 = shift_register(size(TAB_EMG_1,1), TAB_EMG_4, EMG_4);
                        TAB_EMG_5 = shift_register(size(TAB_EMG_1,1), TAB_EMG_5, EMG_5);
                        TAB_EMG_6 = shift_register(size(TAB_EMG_1,1), TAB_EMG_6, EMG_6);
                        TAB_EMG_7 = shift_register(size(TAB_EMG_1,1), TAB_EMG_7, EMG_7);
                        TAB_EMG_8 = shift_register(size(TAB_EMG_1,1), TAB_EMG_8, EMG_8);
                    end
                end
                clf;
                Signal_Processing;
                pause(0.01)
    end
fclose(UDPsock);

