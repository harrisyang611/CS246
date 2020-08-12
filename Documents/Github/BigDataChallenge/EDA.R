library(ggplot2)
rm(list = ls())
setwd("~/Documents/Code/R/BigDataChallenge")

## https://health-infobase.canada.ca/covid-19/
## Updated May 31st
covid <- read.csv('covid19.csv',stringsAsFactors = FALSE)
meta_data <- c('pruid','prname','date','numconf','numprob','numdeaths','numtotal','numtested','numrecover')
dt <- covid[meta_data]
dt$date <- as.Date(dt$date,format = '%d-%m-%Y')
dt$numrecover <- ifelse(dt$numrecover == "N/A",0,dt$numrecover)


filter <- dt$numrecover == ""
dt2 <- dt[!filter,]

imputation <- lm(numrecover ~ prname + numtotal + date + numconf , data = dt2,na.action = 'na.omit')

pred <- predict.lm(imputation,newdata = dt[filter,c('prname','numtotal','date','numconf')] )
dt$numrecover[filter] <- ifelse(pred < 0, 0,pred)

dt$prname <- ifelse( (dt$prname == 'Nunavut' | dt$prname == 'Yukon' | 
                      dt$prname == 'v' | dt$prname == 'Repatriated travellers'),
                     'Other',dt$prname)

province <- c('Alberta','British Columbia','Manitoba','New Brunswick',
              'Newfoundland and Labrador','Nova Scotia','Ontario','Prince Edward Island',
              'Quebec','Saskatchewan','Other','Canada')


for (i in province) {
  
  dt2 <- dt[dt$prname == i,]
  dt2$diffdeaths <- c(0,diff(dt2$numdeaths))
  #dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$diffdeaths))
  dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$numtotal) - as.numeric(dt2$numrecover))
  
  
  model1 <- glm(resp ~ date + numconf +numdeaths ,family=binomial(link=logit),data=dt2)
  summary(model1)
  
  from <- as.Date("2020-05-30")
  to <- as.Date("2020-08-31")
  diff_dates <- as.numeric(to - from) + 1
  
  newdata <- dt2[c('date','numconf','numdeaths')]
  extra <- data.frame( date = seq(from,to,by='day'),
                       numconf = rep(max(newdata$numconf), diff_dates  ),
                       numdeaths = rep(max(newdata$numdeaths), diff_dates )
  )
  newdata <- rbind(newdata,extra)
  newdata <- newdata[newdata$date > as.Date('2020-03-31'),]
  newdata$col <- ifelse(newdata$date >= as.Date('2020-06-01'), "red", "green")
  
  newfit <- predict(model1,newdata = newdata,type = 'response')
  title <- paste('Predicted Chance of Recovery in', i)
  ylab <- 'Chance of Recovery'
  xlab <- 'Date'
  
  #plot(newdata$date,newfit,main = paste('Predicted Chance of Recovery in', i) , xlab = 'Date',ylab = 'Chance of Recovery',type='l',col='blue')
  filename <- paste0('pic/',i,'_predicted_chance.jpg')
  # jpeg(filename, width = 350, height = 350)
  ggplot(newdata, aes(x = date, y = newfit, colour = col,group=1)) +
    geom_line() +
    ggtitle(title) +
    labs(y=ylab,x=xlab)+
    geom_hline(yintercept=0.95,color='blue') +
    scale_color_discrete(labels = c('Past','Future') )
  ggsave(filename,width = 14, height = 9.260416667, units = "cm")
}











dt2 <- dt[dt$prname == 'Canada',]
dt2$diffdeaths <- c(0,diff(dt2$numdeaths))
#dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$diffdeaths))
dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$numtotal) - as.numeric(dt2$numrecover))


model1 <- glm(resp ~ date + numconf +numdeaths ,family=binomial(link=logit),data=dt2)
summary(model1)

from <- as.Date("2020-05-30")
to <- as.Date("2020-08-31")
diff_dates <- as.numeric(to - from) + 1

newdata <- dt2[c('date','numconf','numdeaths')]
extra <- data.frame( date = seq(from,to,by='day'),
                     numconf = rep(max(newdata$numconf), diff_dates  ),
                     numdeaths = rep(max(newdata$numdeaths), diff_dates )
)
newdata <- rbind(newdata,extra)
newdata <- newdata[newdata$date > as.Date('2020-03-31'),]
newdata$col <- ifelse(newdata$date >= as.Date('2020-06-01'), "red", "green")

newfit <- predict(model1,newdata = newdata,type = 'response')
title <- paste('Predicted Chance of Recovery in', i)
ylab <- 'Chance of Recovery'
xlab <- 'Date'

filename <- paste0('pic/Canada_longer_range.jpg')
ggplot(newdata, aes(x = date, y = newfit, colour = col,group=1)) +
  geom_line() +
  ggtitle(title) +
  labs(y=ylab,x=xlab)+
  geom_hline(yintercept=0.95,color='blue') +
  scale_color_discrete(labels = c('Past','Future') )
ggsave(filename,width = 14, height = 9.260416667, units = "cm")





dt2 <- dt[dt$prname == 'Alberta',]
dt2$diffdeaths <- c(0,diff(dt2$numdeaths))
dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$numtotal) - as.numeric(dt2$numrecover))


filter <- dt2$numrecover == ""
dt3 <- dt2[!filter,]

imputation <- lm(numrecover ~ numtotal + date + numconf , data = dt3, na.action = 'na.omit')

pred <- predict.lm(imputation,newdata = dt2[filter,c('numtotal','date','numconf')] )
dt2$numrecover[filter] <- ifelse(pred < 0 , 0,  ifelse(pred > 1162 , 1162, pred))

dt2$diffdeaths <- c(0,diff(dt2$numdeaths))
#dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$diffdeaths))
dt2$resp <- cbind(as.numeric(dt2$numrecover),as.numeric(dt2$numtotal) - as.numeric(dt2$numrecover))

model1 <- glm(resp ~ date + numconf +numdeaths ,family=binomial(link=logit),data=dt2)
summary(model1)

from <- as.Date("2020-05-30")
to <- as.Date("2020-10-31")
diff_dates <- as.numeric(to - from) + 1

newdata <- dt2[c('date','numconf','numdeaths')]
extra <- data.frame( date = seq(from,to,by='day'),
                     numconf = rep(max(newdata$numconf), diff_dates  ),
                     numdeaths = rep(max(newdata$numdeaths), diff_dates )
)
newdata <- rbind(newdata,extra)

newfit <- predict(model1,newdata = newdata,type = 'response')

filename <- paste0('Alberta_predicted_chance_2.jpg')
jpeg(filename, width = 350, height = 350)
plot(newdata$date,newfit,main = paste('Predicted Chance of Recovery in', "Alberta") , xlab = 'Date',ylab = 'Chance of Recovery',type='l',col='blue')
dev.off()
