function y=f_c(x)
  if (x>=-1 && x<0)
    y=1/(1+x^2);
  elseif (x>0 && x<1)
    y=(1/x^2)*sin(x/(1-x))^2;
  elseif (x>=1 && x<=2)
    y=sqrt(2*x-x^2);
  end
end