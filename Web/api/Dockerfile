FROM node:16

RUN useradd -ms /bin/bash ctf

# Create app directory
WORKDIR /usr/src/app
RUN mkdir upload

# Install app dependencies
# A wildcard is used to ensure both package.json AND package-lock.json are copied
# where available (npm@5+)
COPY ./package*.json ./
RUN ls
RUN npm install
# If you are building your code for production
# RUN npm ci --omit=dev

# Bundle app source
COPY . .

RUN chown -R ctf:ctf /usr/src/app
RUN chmod 555 /usr/src/app
RUN chmod -f 555 /usr/src/app/encrypt || :
RUN chmod 700 /usr/src/app/upload
USER ctf

CMD [ "node", "index.js" ]

