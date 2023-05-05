function tab = shift_register(size, tab, a)
    for i = 1 : (size-1)
        tab(i) = tab(i+1);
    end
    tab(size) = a;
end

