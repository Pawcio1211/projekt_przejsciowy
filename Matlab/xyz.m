function q = xyz(f_k)
q_1=[0 f_k(1,4) f_k(1,8) f_k(1,12) f_k(1,16)];
q_2=[0 f_k(2,4) f_k(2,8) f_k(2,12) f_k(2,16)];
q_3=[0 f_k(3,4) f_k(3,8) f_k(3,12) f_k(3,16)];
q=[q_1;q_2;q_3];
end
