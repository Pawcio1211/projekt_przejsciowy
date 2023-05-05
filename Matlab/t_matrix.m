function t = t_matrix(j)
t_01=transformation_matrix(j(1,1),j(2,1),j(3,1),j(4,1));
t_12=transformation_matrix(j(1,2),j(2,2),j(3,2),j(4,2));
t_23=transformation_matrix(j(1,3),j(2,3),j(3,3),j(4,3));
t_34=transformation_matrix(j(1,4),j(2,4),j(3,4),j(4,4));

t_02=t_01*t_12;
t_03=t_02*t_23;
t_04=t_03*t_34;

t=[t_01 t_02 t_03 t_04];
end

