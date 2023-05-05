s_sum_1=squares_sum(TAB_EMG_1);
s_sum_2=squares_sum(TAB_EMG_2);
s_sum_3=squares_sum(TAB_EMG_3);
s_sum_4=squares_sum(TAB_EMG_4);
s_sum_5=squares_sum(TAB_EMG_5);
s_sum_6=squares_sum(TAB_EMG_6);
s_sum_7=squares_sum(TAB_EMG_7);
s_sum_8=squares_sum(TAB_EMG_8);

if(s_sum_1 < 930 && s_sum_2<3100 && s_sum_3<35000 && s_sum_4<2800 && s_sum_5<550 && s_sum_6<400 && s_sum_7<1000 && s_sum_8<250 && ...
    s_sum_1 > 100 && s_sum_2 > 400 && s_sum_3 > 19000 && s_sum_4 > 450 && s_sum_5 < 100 && s_sum_6 > 0 && s_sum_7 > 0 && s_sum_8 > 0 && allow==1)
    allow = 0;
    a_11 = 1;
    angle_1 = 0;
    angle_2 = 0;
    angle_3 = 0;
    angle_4 = 0;
    angle_5 = 0;
    pose = 'Powitanie';     % wszystkie palce proste - wystarczy lekko
elseif(s_sum_1 < 160000 && s_sum_2 < 100000 && s_sum_3<80000 && s_sum_4<130000 && s_sum_5<40000 && s_sum_6<20000 && s_sum_7<105000 && s_sum_8<70000 && ...
    s_sum_1 > 12000 && s_sum_2 > 14000 && s_sum_3 > 10000 && s_sum_4 > 21000 && s_sum_5 < 2500 && s_sum_6 > 1000 && s_sum_7 > 4000 && s_sum_8 > 10000 && allow==1)
    allow = 0;
    a_11 = 1;
    angle_1 = 60;
    angle_2 = 90;
    angle_3 = 90;
    angle_4 = 90;
    angle_5 = 90;
    pose = 'Chwyt';      % wszystkie palce mocno zaciœniête w piêœæ
elseif(s_sum_1<0 && s_sum_2<0 && s_sum_3<0 && s_sum_4<0 && s_sum_5<0 && s_sum_6<0 && s_sum_7>0 && s_sum_8>5999990 && allow==1)
    allow = 0;
    a_11 = 1;
    angle_1 = 60;
    angle_2 = 0;
    angle_3 = 60;
    angle_4 = 60;
    angle_5 = 60;
    pose = 'Wskazanie';     % najpierw lekko ugiac wszystkie place, potem wyprostowac palec 2
elseif(s_sum_1<0 && s_sum_2<0 && s_sum_3<0 && s_sum_4>1000 && s_sum_5<5000 && s_sum_6>1000 && s_sum_7>500 && s_sum_8>400 && allow==1)
    allow = 0;
    a_11 = 0;
    angle_1 = -5;
    angle_2 = 60;
    angle_3 = 60;
    angle_4 = 60;
    angle_5 = 60;
    pose = 'OK';        % znak ok lekko, potem doscisnac palce 2-5
elseif(s_sum_4>2000000 && s_sum_5>40000 && allow==1)
    allow = 0;
    a_11 = 4.5;
    angle_1 = 43;
    angle_2 = 52;
    angle_3 = 10;
    angle_4 = 5;
    angle_5 = 2;
    pose = 'Precyzyjny';	% najpierw mocno palec 1 do 2, potem wyprostowac reszte
elseif(s_sum_1<0 && s_sum_2<2000 && s_sum_3<2000 && s_sum_4<10000 && s_sum_5>80000 && s_sum_6<10000 && s_sum_7<6000 && s_sum_8<6000 && allow==1)
    allow = 0;
    a_11 = 2;
    angle_1 = 60;
    angle_2 = 0;
    angle_3 = 0;
    angle_4 = 60;
    angle_5 = 60;
    pose = 'Victoria';   % najpierw lekko zacisnac, potem palce 2 i 3 mocno wyprostowac
elseif(s_sum_1>1000000 && s_sum_2<2000 && s_sum_3<1000 && s_sum_4<3000 && s_sum_5>20000 && s_sum_6>20000 && s_sum_7<2000 && s_sum_8>1000 && allow==1)
    allow = 0;
    a_11 = 1;
    angle_1 = 0;
    angle_2 = 0;
    angle_3 = 90;
    angle_4 = 90;
    angle_5 = 0;
    pose = 'Mano cornuta';      % mocno wyprostowac palce 1, 2, 5
elseif(allow == 1)
    a_11 = 1;
    angle_1 = 30;
    angle_2 = 20;
    angle_3 = 20;
    angle_4 = 20;
    angle_5 = 20;
    pose = 'rest';
end

if(s_sum_1+s_sum_2+s_sum_3+s_sum_4+s_sum_5+s_sum_6+s_sum_7+s_sum_8<2000)
    allow = 1;
end

run(a_11, angle_1, angle_2, angle_3, angle_4, angle_5);
fprintf('%s,  %d,  %d,  %d,  %d,  %d,  %d,  %d,  %d \n ', pose, s_sum_1, s_sum_2, s_sum_3, s_sum_4, s_sum_5, s_sum_6, s_sum_7, s_sum_8);