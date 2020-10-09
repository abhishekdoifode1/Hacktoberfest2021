import csv
import heapq

from collections import defaultdict
from operator import itemgetter

from surprise import KNNBasic
from surprise import Dataset
from surprise import Reader
reader = Reader(line_format='user item rating timestamp', sep=',', skip_lines=1)
ratings_data = Dataset.load_from_file('ratings.csv', reader=reader)

movieID_2_name = {}
name_2_movieID = {}

with open('movies.csv', newline='', encoding='ISO-8859-1') as csvfile:
    
    mov_Reader = csv.reader(csvfile)
    next(mov_Reader)  
    
    for x in mov_Reader:
        movie_ID = int(x[0])
        movie_Name = x[1]
        movieID_2_name[movie_ID] = movie_Name
        name_2_movieID[movie_Name] = movie_ID
simi_options = {'name' : 'cosine','user_based' : False }
simi_algo = KNNBasic(sim_options = simi_options)
trainSet = ratings_data.build_full_trainset()
simi_algo.fit(trainSet)
simi_matrix = simi_algo.compute_similarities()
_id = 65
k = 5

user_inner_id = trainSet.to_inner_uid(str(_id))
rated_by_user = trainSet.ur[user_inner_id]        
kneighbour = heapq.nlargest(k, rated_by_user, lambda x : x[1])
already_watched = {}
for mv in trainSet.ur[user_inner_id]:
    already_watched[mv] = 1
finalCandidates = defaultdict(float)
for first_mv in kneighbour:
    for second_mv in range(trainSet.n_items):
        if int(first_mv[0]) != int(second_mv):
            finalCandidates[second_mv] += (first_mv[1]/5.0)*(simi_matrix[first_mv[0]][second_mv])
finalList = sorted(finalCandidates.items(), key=itemgetter(1), reverse=True)
count = 0
print('Recommendations for user are-')
print()
for mov_id,score in finalList:
    if not mov_id in already_watched:
        movieId = trainSet.to_raw_iid(mov_id)
        count += 1
        print(movieID_2_name[int(movieId)], '  ', score)
        if count == 10:
            break