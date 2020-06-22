# LeetCode1396_DesignUndergroundSystem.py
class UndergroundSystem:
	def __init__( self ):
		self.people = { }
		self.average = { }

	def checkIn( self, id: int, stationName: str, t: int ) -> None:
		self.people[id] = ( stationName, t )

	def checkOut( self, id: int, stationName: str, t: int ) -> None:
		person = self.people[id]
		del self.people[id]

		station = person[0] + stationName
		time = t - person[1]

		if station in self.average:
			self.average[station].append( time )
		else:
			self.average[station] = [ time ]


	def getAverageTime( self, startStation: str, endStation: str ) -> float:
		timeList = self.average[ startStation + endStation ]
		aver = sum( timeList ) / len( timeList )

		return aver
