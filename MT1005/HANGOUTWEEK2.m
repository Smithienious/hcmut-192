hold on
x=linspace(1,4,30);
y=linspace(-2,0,30);
[x, y]=meshgrid(x,y);
z=3*y.^2-2*x.^2+x;
surf(x,y,z,'FaceColor','b','FaceAlpha',0.4,'EdgeColor','none')
plot3(2,-1,-3,'*','Color','r','linewidth',5)
z=-7*x-6*y+5;
surf(x,y,z,'FaceColor','y')

rotate3d on