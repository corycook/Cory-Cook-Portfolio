grid=1000 // Sets the size of the test area
ps=8 // Sets the plot size (size per unit area)
datarate=1000
A = rand(grid,grid,2)
A = A*ps
// This is the signal degredation based on distance
function b=sig(t)
    b=sqrt(-(t-40)/40)
endfunction
// Caluclates the distance between nodes
function d=dist(curr,next)
    d=sqrt((curr(1)-next(1))^2+(curr(2)-next(2))^2)
endfunction
// Gets the coordinates of the node
function coords=cor(x)
    coords=[x(1)+A(x(1),x(2),1)/ps x(2)+A(x(1),x(2),2)/ps]
endfunction
// Gets the next node address
function out=np(u, v)
    if u==v then
        out=u
    else
        out=u+((v-u)/abs(v-u))
    end
endfunction
function [latency, throughput]=set_val(start_pos,end_pos,speed)
    latency=0
    throughput=speed
    current_pos = start_pos
    while or(current_pos~=end_pos)
        next_pos(1,1)=np(current_pos(1), end_pos(1))
        next_pos(1,2)=np(current_pos(2), end_pos(2))
        latency=latency+1
        val=sig(dist(cor(current_pos), cor(next_pos)))*datarate
        if val<throughput then
            throughput=val
        end
        current_pos = next_pos
    end
endfunction
for i=1:1000
    start_pos=[ceil(grid*rand()) ceil(grid*rand())]
    end_pos=[ceil(grid*rand()) ceil(grid*rand())]
    startp(i,:)=start_pos
    endp(i,:)=end_pos
    [lat(i), band(i)] = set_val(start_pos,end_pos,datarate)
end
