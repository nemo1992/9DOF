from visual import *

print "Simulation of a Ferris Wheel"
print "----------------------------"
print ""
print "The yellow vector is the force of the chair on you. The blue vector is the gravitational force of the Earth on you. The green vector is the net force on you."
print ""
print "Change the period, T, to 5 seconds and you'll notice that you need a seatbelt at the top of the Ferris Wheel"
print ""
print "Change T to 10 seconds and you don't need a seatbelt at the top."


dtheta = 45./180.*pi #increment angle to draw ferris wheel bars
r=0.3 #radius of Ferris wheel
theta0=0. #starting angle
rodRadius=dtheta/10. #radius of wheel spokes
rodColor=color.yellow #color of wheel spokes

m=90. #mass of person

scene.autoscale=0
scene.range=1.2*r

phi=0. #angle of rotation
T=5.    # period of rotation
omega=2.*pi/T #initial angular speed
alpha=0. #angular acceleration

#lists
rods=[]
rods1=[]


#create objects
for theta in arange(theta0, 2.*pi, dtheta):
	chairPos=vector(r*cos(theta),r*sin(theta),0)
	rods.append(cylinder(radius=rodRadius, pos=vector(-0.1,0,0), axis=chairPos, color=rodColor,length=0.01))
	chairPos1=vector(r*cos(theta),r*sin(theta),0)
	rods1.append(cylinder(radius=rodRadius, pos=vector(0.1,0,0), axis=chairPos, color=rodColor,length=0.01))
	
        
#time interval
#dt=T/1000.
dt=T/100.

while 1:
	rate(10)
	omega=omega+alpha*dt
	dphi=omega*dt
	s=omega*r
	
        loop=0
	if loop:
		print "a"
		
	for i in range(len(rods)):
		rod=rods[i]
		rod.axis=rotate(rod.axis,angle=dphi)
		rod1=rods1[i]
		rod1.axis=rotate(rod1.axis,angle=dphi)
	    
		
