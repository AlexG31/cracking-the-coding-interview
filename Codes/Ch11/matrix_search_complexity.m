%complexity analysis 
n=1:1e4;
quad_y=n.^(log2(3));
bws_y=zeros(size(n));
for ind=n
    val=n(ind);
    for p2 =0:100
        if 2^p2>n(ind)
            break;
        end
        val=val+2^p2*(log2(n(ind))-p2);
    end
    bws_y(ind)=val;
end

plot(n,quad_y);
hold on;
grid on;
plot(n,bws_y);
legend('quad','bws');