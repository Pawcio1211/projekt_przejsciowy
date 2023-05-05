function tab = shift_register_loop(size, tab)
    b = tab(1);
    for i = 1 : (size-1)
        tab(i) = tab(i+1);
    end
    tab(size) = b;
end


