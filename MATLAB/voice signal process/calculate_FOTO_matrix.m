function calculate_FOTO_matrix(data,file_out1,file_out2)
%clear all
%close all
%fid=fopen('I:\11.26\GF2_PMS1_E121.3_N50.8_20150620_L1A0000873086-PAN1\GF2_E1213_N508_20150620','rb');
[line,sample]=size(data);
%line=27620;
%sample=29200;
patch_size=50;
line_num=floor(line/patch_size);
sample_num=floor(sample/patch_size);
%temp=fread(fid,line*sample,'uint16');
%data=reshape(temp,sample,line)';
bin_num=patch_size/2;
%fid_out0=fopen('r_sepctra','wb'); 
%fid_out1=fopen('H:\ZY03\puer2\data_ni\sub1_r_sepctra_score','wb'); 
num=0;
for i=1:line_num-1
    line_start=(i-1)*patch_size+1;
    line_end=i*patch_size;
    for j=1:sample_num-1
        sample_start=(j-1)*patch_size+1;
        sample_end=j*patch_size;
        data_sub=data(line_start:line_end+1,sample_start:sample_end+1);
        Y = fftshift(fft2(data_sub));
       % Y=Y/max(max(abs(Y))); 
        r_spectra(1:patch_size/2)=0;
        num00=0;
        for ii=1:patch_size/2
            for jj=1:patch_size/2
                dist=sqrt((ii-bin_num)^2+(jj-bin_num)^2);
                pos=ceil(dist)+1;
                if(pos<=bin_num)
                    num00=num00+1;
                    r_spectra(pos)=r_spectra(pos)+abs(Y(ii,jj));  
                end
            end
        end
        r_spectra=r_spectra/num00;
        plot(r_spectra,'-+');
        num=num+1;        
        data_out(num,1:bin_num)=r_spectra;
       %fwrite(fid_out0,r_spectra,'float');
       % fid_out1=fopen('H:\ZY03\puer2\data_ni\sub1','wb')'   
        %fwrite(fid_out1,data_sub','float');      
        %fid_out2=fopen('H:\ZY03\puer2\data_ni\sub1_fft','wb')'
        %fwrite(fid_out2,Y_real','float');
        %fwrite(fid_out2,Y_imag','float');        
        
    end
    i
end
[coeff,score,latent,tsquared]=wpca(data_out);

fid_out1=fopen(file_out1,'wb'); 
fwrite(fid_out1,score(1:num,1),'float');
fwrite(fid_out1,score(1:num,2),'float');
fwrite(fid_out1,score(1:num,3),'float');
fwrite(fid_out1,score(1:num,4),'float');
fclose(fid_out1);

score1=score(1:num,1);
score_mat1=reshape(score1,sample_num-1,line_num-1);
 total(1:sample_num-1)=0;
for iii=1:line_num-1
    total=total+score_mat1(:,iii)';
end
mean1= mean(total);
for kkk=1:line_num-1
    total1(kkk,1:sample_num-1)=total;
end
%fid_out2=fopen('I:\11.26\GF2_PMS1_E121.3_N50.8_20150620_L1A0000873086-PAN1\sub1_r_sepctra_score1_delta','wb');
%fwrite(fid_out2,total1'/(line_num-1),'float');
%fclose(fid_out2);

score2=score(1:num,2);
score_mat2=reshape(score2,sample_num-1,line_num-1);
 total(1:sample_num-1)=0;
for iii=1:line_num-1
    total=total+score_mat2(:,iii)';
end
mean2= mean(total);
for kkk=1:line_num-1
    total2(kkk,1:sample_num-1)=total;
end
%fid_out2=fopen('I:\11.26\GF2_PMS1_E121.3_N50.8_20150620_L1A0000873086-PAN1\sub1_r_sepctra_score2_delta','wb');
%fwrite(fid_out2,total2'/(line_num-1),'float');
%fclose(fid_out2);

score3=score(1:num,3);
score_mat3=reshape(score3,sample_num-1,line_num-1);
 total(1:sample_num-1)=0;
for iii=1:line_num-1
    total=total+score_mat3(:,iii)';
end
mean3= mean(total);
for kkk=1:line_num-1
    total3(kkk,1:sample_num-1)=total;
end
%fid_out2=fopen('I:\11.26\GF2_PMS1_E121.3_N50.8_20150620_L1A0000873086-PAN1\sub1_r_sepctra_score3_delta','wb');
%fwrite(fid_out2,total3'/(line_num-1),'float');
%fclose(fid_out2);

score4=score(1:num,4);
score_mat4=reshape(score4,sample_num-1,line_num-1);
 total(1:sample_num-1)=0;
for iii=1:line_num-1
    total=total+score_mat4(:,iii)';
end
mean4= mean(total);
for kkk=1:line_num-1
    total4(kkk,1:sample_num-1)=total;
end
%fid_out2=fopen('I:\11.26\GF2_PMS1_E121.3_N50.8_20150620_L1A0000873086-PAN1\sub1_r_sepctra_score4_delta','wb');
%fwrite(fid_out2,total4'/(line_num-1),'float');
%fclose(fid_out2);


fid_out2=fopen(file_out2,'wb'); 
fwrite(fid_out2,score_mat1-total1'/(line_num-1)+mean1,'float');
fwrite(fid_out2,score_mat2-total2'/(line_num-1)+mean2,'float');
fwrite(fid_out2,score_mat3-total3'/(line_num-1)+mean3,'float');
fwrite(fid_out2,score_mat4-total4'/(line_num-1)+mean4,'float');
fclose(fid_out2);
end
