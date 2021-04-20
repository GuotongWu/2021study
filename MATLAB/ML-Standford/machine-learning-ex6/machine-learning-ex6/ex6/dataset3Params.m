function [C, sigma] = dataset3Params(X, y, Xval, yval)
%DATASET3PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = DATASET3PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 1;
sigma = 0.3;


% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%

multiplication = [0.01 0.03 0.1 0.3 1 3 10 30];
mean_predictions = zeros(length(multiplication)^2,1);
i = 1;
for k = 1:length(multiplication)
    for j = 1:length(multiplication)
        C = multiplication(k);
        sigma = multiplication(j);
        model = svmTrain(X,y,C,@(x1,x2) gaussianKernel(x1,x2,sigma)); % 这里不是很清楚
        predictions = svmPredict(model, Xval);
        mean_predictions(i) = mean(double(predictions ~= yval));
        i = i+1;
    end
end

rep = reshape(mean_predictions,[length(multiplication),length(multiplication)]);
pos = min(min(rep));
[pos_x,pos_y] = find(rep == pos);
C = multiplication(pos_y);
sigma = multiplication(pos_x);

% =========================================================================

end
